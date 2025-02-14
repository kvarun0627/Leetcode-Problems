class ProductOfNumbers {
public:
    vector<int>p_m;
    int size;
    ProductOfNumbers() {
        p_m.push_back(1);
        size=0;
    }
    
    void add(int num) {
        if(num==0)
        {
            p_m={1};
            size=0;
        }
        else
        {
            p_m.push_back(p_m.back()*num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k>size)
        {
            return 0;
        }
        return p_m[size]/(p_m[size-k]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */