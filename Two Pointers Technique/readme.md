# টু পয়েন্টার টেকনিক (Two Pointer Technique)

টু পয়েন্টার টেকনিক একটি প্রোগ্রামিং কৌশল যা মূলত অ্যারে বা লিংকড লিস্টের উপর কাজ করে। এই পদ্ধতিতে দুটি পয়েন্টার ব্যবহার করে ডেটা স্ট্রাকচার ট্রাভার্স করা হয়।

## মূল ধারণা

- দুটি পয়েন্টার ব্যবহার করে অ্যারে বা লিস্ট স্ক্যান করা
- সময় জটিলতা কমানোর জন্য ব্যবহৃত হয়
- সাধারণত O(n) টাইম কমপ্লেক্সিটি

## প্রয়োগ ক্ষেত্র

1. সর্টেড অ্যারেতে টার্গেট সাম খোঁজা
2. অ্যারে থেকে ডুপ্লিকেট এলিমেন্ট রিমুভ করা
3. পালিনড্রোম চেক করা
4. অ্যারে রিভার্স করা

## সুবিধা

- মেমরি এফিসিয়েন্ট
- সহজে বাস্তবায়নযোগ্য
- অনেক সময় নেস্টেড লুপের প্রয়োজন এড়ানো যায়

## ব্যবহার উদাহরণ

```cpp
// সর্টেড অ্যারেতে টার্গেট সাম খোঁজার উদাহরণ
bool findPair(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left < right) {
        if (arr[left] + arr[right] == target) {
            return true;
        }
        else if (arr[left] + arr[right] < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return false;
}
```


some problems about two-pointer
Find the closest pair from two sorted arrays
Find the pair in array whose sum is closest to x
Find all triplets with zero sum
Find a triplet that sum to a given value
Find a triplet such that sum of two equals to third element
Find four elements that sum to a given value
Trapping Rain Water
