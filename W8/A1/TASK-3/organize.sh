#!/bin/bash

# Set the Downloads directory (Modify if needed)
DOWNLOADS_DIR="$HOME/Downloads"

# Create necessary folders
mkdir -p "$DOWNLOADS_DIR/Images"
mkdir -p "$DOWNLOADS_DIR/Documents"
mkdir -p "$DOWNLOADS_DIR/Videos"
mkdir -p "$DOWNLOADS_DIR/Zip"
mkdir -p "$DOWNLOADS_DIR/Others"

# Move files into appropriate folders
for file in "$DOWNLOADS_DIR"/*; do
    # Skip directories
    [[ -d "$file" ]] && continue
    
    # Get file extension
    ext="${file##*.}"
    ext="${ext,,}"
    
    case "$ext" in
        jpg|jpeg|png|gif|bmp|svg|webp)
            mv "$file" "$DOWNLOADS_DIR/Images/" ;;
        pdf|docx|doc|xls|xlsx|ppt|pptx|txt)
            mv "$file" "$DOWNLOADS_DIR/Documents/" ;;
        mp4|mov|avi|mkv|flv|wmv)
            mv "$file" "$DOWNLOADS_DIR/Videos/" ;;
        zip|tar|gz|bz2|rar)
            mv "$file" "$DOWNLOADS_DIR/Zip/" ;;
        *)
            mv "$file" "$DOWNLOADS_DIR/Others/" ;;
    esac

done

echo "Downloads folder organized successfully!"
