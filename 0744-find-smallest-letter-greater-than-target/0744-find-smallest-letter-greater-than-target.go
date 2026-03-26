func nextGreatestLetter(letters []byte, target byte) byte {
    n := len(letters)
    left := 0
    right := n-1

    for left <= right {
        mid := left + (right-left) / 2;

        if letters[mid] <= target {
            left = mid + 1
        } else if letters[mid] > target {
            right = mid - 1
        }
    }

    if left == n {
        return letters[0];
    }

    return letters[left]
}