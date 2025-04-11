#!/bin/bash

# Number of blocks to fetch (first argument)
NUM_BLOCKS=$1
OUTPUT_FILE="blocks.json"

# Start JSON array
# echo "[" > "$OUTPUT_FILE"

# Get the latest block hash
LATEST_HASH=$(wget -qO- "https://api.blockcypher.com/v1/btc/main" | grep -oP '"hash":\s*"\K[^"]+')

for (( i=0; i<NUM_BLOCKS; i++ ))
do
   # echo "Fetching block $i with hash: $LATEST_HASH"

    # Fetch full block data
    BLOCK_JSON=$(wget -qO- "https://api.blockcypher.com/v1/btc/main/blocks/$LATEST_HASH")

    # Extract required fields using grep/sed
    HASH=$(echo "$BLOCK_JSON" | grep -oP '"hash":\s*"\K[^"]+')
    HEIGHT=$(echo "$BLOCK_JSON" | grep -oP '"height":\s*\K[0-9]+')
    TOTAL=$(echo "$BLOCK_JSON" | grep -oP '"total":\s*\K[0-9]+')
    TIME=$(echo "$BLOCK_JSON" | grep -oP '"time":\s*"\K[^"]+')
    RELAYED_BY=$(echo "$BLOCK_JSON" | grep -oP '"relayed_by":\s*"\K[^"]+')
    PREV_BLOCK=$(echo "$BLOCK_JSON" | grep -oP '"prev_block":\s*"\K[^"]+')

    # Build minimal JSON object
    echo "  {" >> "$OUTPUT_FILE"
    echo "    \"hash\": \"$HASH\"," >> "$OUTPUT_FILE"
    echo "    \"height\": $HEIGHT," >> "$OUTPUT_FILE"
    echo "    \"total\": $TOTAL," >> "$OUTPUT_FILE"
    echo "    \"time\": \"$TIME\"," >> "$OUTPUT_FILE"
    echo "    \"relayed_by\": \"$RELAYED_BY\"," >> "$OUTPUT_FILE"
    echo "    \"prev_block\": \"$PREV_BLOCK\"" >> "$OUTPUT_FILE"
    echo -n "  }" >> "$OUTPUT_FILE"

    # Add comma if not the last block
    if [ $i -lt $((NUM_BLOCKS - 1)) ]; then
        echo "," >> "$OUTPUT_FILE"
    else
        echo "" >> "$OUTPUT_FILE"
    fi

    # Prepare for next iteration
    LATEST_HASH="$PREV_BLOCK"
    if [ -z "$LATEST_HASH" ]; then
        echo "Reached genesis block."
        break
    fi
done

# End JSON array
echo "]" >> "$OUTPUT_FILE"

echo "Saved $i block(s) with selected fields to $OUTPUT_FILE"

