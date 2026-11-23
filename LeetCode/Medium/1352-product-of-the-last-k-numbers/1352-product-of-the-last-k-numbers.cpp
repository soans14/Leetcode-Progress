class ProductOfNumbers {
public:
    vector<int> product,zero,stream;
    int temp=1,count=0,ans,size;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        stream.push_back(num);
        if(num==0){
            temp=1;
            product.push_back(0);
            zero.push_back(++count);
        }
        else{
            temp*=num;
            product.push_back(temp);
            zero.push_back(count);
        }
    }
    
    int getProduct(int k) {
        size=product.size();
        if(size-1-k>=0&&zero[size-1]==zero[size-1-k]&&stream[size-k-1]!=0){
            return product[size-1]/product[size-1-k];
        }
        else if((size-k-1>=0&&zero[size-1]==zero[size-1-k])||(size-k-1<0&&zero[size-1]==0)){
            return product[size-1];
        }
        else{
            return 0;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */