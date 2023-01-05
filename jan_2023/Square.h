class Square{

private:
    int corner1_;
    int corner2_;
    int corner3_;
    int corner4_;

public:
    Square(int corner1, int corner2, int corner3, int corner4);
    vector<int> getSquare();
    void newSquare();
    bool isZero();

};
