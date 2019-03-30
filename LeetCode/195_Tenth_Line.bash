# Read from the file file.txt and output the tenth line to stdout.
#!/bin/bash
input="file.txt"
count=1
while IFS= read line
do
    if [[ "$count" -eq 10 ]]; then
    echo $line
    exit 1
    fi
    
    count=$((count+1))
  
done < "$input"
if [[ "$count" -le 10 ]]; then
    echo ""
fi
