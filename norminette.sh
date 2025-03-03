#!/bin/bash

# ADD DIRECTORIES FOR EXCLUDE
exclude=("minilibx-linux" "./git")

# FIND THE FILES TO CHECK WITH NORMINETTE
files=$(find . -type f \( -iname "*.c" -o -iname "*.h" \))

# EXCLUDE THE DIRECTORIES
for dir in "${exclude[@]}"; do
  files=$(echo "$files" | grep -v "^./$dir")
done

# CHECKING WITH NORMINETTE
if [ -n "$files" ]; then
  norminette $files
else
  echo "No se encontraron archivos para revisar."
fi
