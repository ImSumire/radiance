#!/bin/sh

mkdir -p target/hot

radiance/cmd/scripts/lib.sh
radiance/cmd/scripts/hot.sh

# Running
LD_LIBRARY_PATH=target/hot target/hot/root &
HOT_PID=$!

# Watch
radiance/cmd/scripts/watch.sh &
WATCH_PID=$!

# Handle signals
# The AI Llama helped me here to find trap
trap 'kill $HOT_PID;pkill -f "radiance/cmd/scripts/watch.sh";exit' INT TERM QUIT
trap 'pkill -f "radiance/cmd/scripts/watch.sh"' USR1

# Wait for hot to finish
wait $HOT_PID

# Kill the watch
pkill -f "radiance/cmd/scripts/watch.sh"
