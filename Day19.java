class Solution {

    // approach - 1 - PriorityQueue
    public List<String> topKFrequent(String[] words, int k) {
        
       Map<String, Integer> counterMap = new HashMap<>();
        Queue<Map.Entry<String, Integer>> queue = new PriorityQueue<>(
                (a, b) ->
                {
                    if (Objects.equals(a.getValue(), b.getValue()))
                        return a.getKey().compareTo(b.getKey());
                    return b.getValue() - a.getValue();
                }
        );

        List<String> frequentWords = new ArrayList<>();

        for (String word : words) {
            counterMap.put(word, counterMap.getOrDefault(word, 0) + 1);
        }

        queue.addAll(counterMap.entrySet());

        while (k-- > 0)
            frequentWords.add(queue.remove().getKey());

        return frequentWords;
    }
}


// approach - 2 - TreeMap
TreeMap<String, Integer> map = new TreeMap<>();
        for (String word : words) {
            if (map.containsKey(word)) {
                map.put(word, map.get(word) + 1);
            } else {
                map.put(word, 1);
            }
        }

        // System.out.println(map);
        List<String> sortedByValue = map
                .entrySet()
                .stream()
                .sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
                .map(Map.Entry::getKey)
                .collect(Collectors.toList());

        List<String> ans = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            ans.add(sortedByValue.get(i));
        }
        return ans;