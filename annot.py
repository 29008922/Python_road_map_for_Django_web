#!/usr/bin/env python3
import asyncio

def add_num(a: float, b: float) -> float:
    return a + b

print(add_num(2.0, 4.0))

def concat(str1: str, str2: str) -> str:
    return str1 + str2

print("hello " + " world ")

async def main():
    print("Hello.......")
    await asyncio.sleep(4)
    print(".....world")

asyncio.run(main())