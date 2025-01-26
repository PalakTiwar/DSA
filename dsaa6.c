int maxProfit(int* prices, int pricesSize) {
    int minPrice = INT_MAX;  
    int maxProfit = 0;      
    for (int i = 0; i < pricesSize; i++) {
        
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}
