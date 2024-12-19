#!/usr/bin/env python3
import asyncio

async def print_num():
    print("one")
    await asyncio.sleep(2)
    print("two")

async def main():
    await asyncio.gather(print_num(), print_num(), print_num())

if __name__ == "__main__":
    import time
    s = time.perf_counter()
    asyncio.run(main())
    elapsed = time.perf_counter() - s
    print(f"{__file__} executed in {elapsed: 0.2f} seconds,")