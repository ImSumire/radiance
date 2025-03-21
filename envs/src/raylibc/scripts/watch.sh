#!/bin/sh

DIR="src"
WATCH_BANNER="\e[35;1mwatch\e[0m"

printf "$WATCH_BANNER Watching for each files of $DIR...\n"

# -q: No "welcome" message
# -m: monitor continuously
# -r: recursive monitoring
# -e close_write: specifies the close event when the file has been wrote
# The AI Llama helped me here to find inotifywait
inotifywait -q -m -r -e close_write "$DIR" |
while read dir events filename; do
    printf "$WATCH_BANNER $dir$filename modified\n" &&
    scripts/common/dlib.sh
done
