class MedianFinder {
public:

    priority_queue<int> left;
    priority_queue<int,vector<int> , greater<int>> right;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if(right.empty() || num >= right.top())
            right.push(num);
        else left.push(num);

        if(left.size() > right.size()){
            right.push(left.top());
            left.pop();
        }

        if(right.size() > left.size() + 1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            return (left.top() + right.top()) / 2.0;
        }

        return right.top();
    }
};