func numIdenticalPairs(nums []int) int {
    m := make(map[int]int)
    ans := 0
    for _, num := range nums {
        ans += m[num]
        m[num]++
    }
    
    return ans
}