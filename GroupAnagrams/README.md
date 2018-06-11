
Given an array of strings, group anagrams together.

**Example:**
```
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```
**Note:**
All inputs will be in lowercase.
The order of your output does not matter.

Solution is O(nklogk), with n being number of strings and k the length of longest string.