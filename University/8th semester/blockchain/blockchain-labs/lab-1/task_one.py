import hashlib
import json

def compute_hash(block):
    """
    Computes the SHA-256 hash of the block’s content.
    We remove the 'hash' field itself before hashing, so changes
    can be detected. Includes 'data', 'index', and 'previousHash'.
    """
    temp = dict(block)  # Make a shallow copy
    temp.pop("hash", None)  # Remove 'hash' if present
    # Convert to JSON string (with sorted keys) for consistent hashing
    block_string = json.dumps(temp, sort_keys=True)
    return hashlib.sha256(block_string.encode('utf-8')).hexdigest()

def create_genesis_block():
    """
    Creates the first block in the chain (index=0) with no previousHash.
    """
    data = ["Hello", "Shahbaz Siddiqui1", "NuFAST"]
    genesis_block = {
        "index": 0,
        "data": data,
        "previousHash": None  # No parent block
    }
    # Compute its hash
    genesis_block["hash"] = compute_hash(genesis_block)
    return genesis_block

def add_block(blockchain, new_data):
    """
    Creates a new block and appends it to the chain.
    The 'previousHash' references the hash of the last block in the chain.
    """
    last_block = blockchain[-1]
    new_index = last_block["index"] + 1

    new_block = {
        "index": new_index,
        "data": new_data,
        "previousHash": last_block["hash"]
    }
    new_block["hash"] = compute_hash(new_block)
    blockchain.append(new_block)

def verify_chain(blockchain):
    """
    Verifies that:
      1) each block's hash is correct for its content, and
      2) each block's previousHash matches the actual hash of the block before it.
    Returns True if the chain is valid; False otherwise.
    """
    for i in range(len(blockchain)):
        block = blockchain[i]
        
        # Recompute the block’s hash and compare to stored
        recalculated_hash = compute_hash(block)
        if block["hash"] != recalculated_hash:
            print(f"Block {i} has been tampered with!")
            return False
        
        # If not the first block, check that previousHash matches the actual hash of the previous block
        if i > 0:
            prev_block = blockchain[i - 1]
            if block["previousHash"] != prev_block["hash"]:
                print(f"Block {i} has an incorrect previousHash link!")
                return False
    return True

# ------------------- DEMO -------------------
if __name__ == "__main__":
    # 1. Create the genesis (first) block
    blockchain = [create_genesis_block()]
    print("Genesis block created:")
    print(json.dumps(blockchain, indent=2), "\n")
    
    # 2. Add a second block (Data2)
    add_block(blockchain, ["Hello again", "Shahbaz Siddiqui1", "NuFAST"])
    print("After adding second block (Data2):")
    print(json.dumps(blockchain, indent=2), "\n")
    
    # 3. Add a third block (Data3)
    add_block(blockchain, ["Third block data", "Sohaib", "No encryption"])
    print("After adding third block (Data3):")
    print(json.dumps(blockchain, indent=2), "\n")
    
    # 4. Verify the entire chain is intact
    print("Is the chain valid initially?", verify_chain(blockchain), "\n")
    
    # 5. Tamper with the data in the second block
    print("Tampering with block 1's data...")
    blockchain[1]["data"][0] = "Tampered!"
    
    # 6. Re-verify to show it detects tampering
    print("Is the chain valid after tampering?", verify_chain(blockchain))


# key takeaway is how to build and verify a linked list of hashed data blocks.






