#!/bin/sh

mkdir -p target/hot

scripts/common/dlib.sh
scripts/common/hotcore.sh

# Running
LD_LIBRARY_PATH=target/hot target/hot/main &
HOT_PID=$!

# Watch
scripts/watch.sh &
WATCH_PID=$!

# Handle signals
# The AI Llama helped me here to find trap
trap 'kill $HOT_PID;pkill -f "scripts/watch.sh";exit' INT TERM QUIT
trap 'pkill -f "scripts/watch.sh"' USR1

# Wait for hot to finish
wait $HOT_PID

# Kill the watch
pkill -f "scripts/watch.sh"
