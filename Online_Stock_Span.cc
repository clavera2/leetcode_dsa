class StockSpanner {
private:
    vector<int> prices;
public:
    StockSpanner() = default;
    
    int next(int price) {
        prices.push_back(price);
        int head = prices.size()-1;
        int count = 0;
        while (head >= 0 && prices[head] <= price) {
            count++;
            head--;
        }
        return count;    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */