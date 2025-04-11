#!/bin/bash

# Number of blocks to fetch from the first argument
NUM_BLOCKS=$1
OUTPUT_FILE="blocks.json"

# Start the JSON array
echo "[" > "$OUTPUT_FILE"

# Get latest block hash
LATEST_HASH=$(wget -qO- "https://api.blockcypher.com/v1/btc/main" | grep -oP '"hash":\s*"\K[^"]+')

for (( i=0; i<NUM_BLOCKS; i++ ))
do
    # Fetch full block JSON
    BLOCK_JSON=$(wget -qO- "https://api.blockcypher.com/v1/btc/main/blocks/$LATEST_HASH")

    # Extract fields
    HASH=$(echo "$BLOCK_JSON" | grep -oP '"hash":\s*"\K[^"]+')
    HEIGHT=$(echo "$BLOCK_JSON" | grep -oP '"height":\s*\K[0-9]+')
    TOTAL=$(echo "$BLOCK_JSON" | grep -oP '"total":\s*\K[0-9]+')
    TIME=$(echo "$BLOCK_JSON" | grep -oP '"time":\s*"\K[^"]+')
    RELAYED_BY=$(echo "$BLOCK_JSON" | grep -oP '"relayed_by":\s*"\K[^"]+')
    PREV_BLOCK=$(echo "$BLOCK_JSON" | grep -oP '"prev_block":\s*"\K[^"]+')

    # Add comma **before** the block, but skip it on the first block
    if [ $i -ne 0 ]; then
        echo "," >> "$OUTPUT_FILE"
    fi

    # Append block JSON
    {
      echo "  {"
      echo "    \"hash\": \"$HASH\","
      echo "    \"height\": $HEIGHT,"
      echo "    \"total\": $TOTAL,"
      echo "    \"time\": \"$TIME\","
      echo "    \"relayed_by\": \"$RELAYED_BY\","
      echo "    \"prev_block\": \"$PREV_BLOCK\""
      echo -n "  }"
    } >> "$OUTPUT_FILE"

done

# Close the JSON array
echo "" >> "$OUTPUT_FILE"
echo "]" >> "$OUTPUT_FILE"

