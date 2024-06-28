#include <iostream>
using std::cout;
using std::endl;

class Sample
{
public:
    Sample();
    void Dispaly();
private:
    int i;
    static int k;
};

Sample::Sample()
{
    i=0;
    k++;
}

void Sample::Dispaly()
{
    cout<<"i="<<i<<",k="<<k<<endl;
}

int Sample::k=0;

int main()
{
    Sample a,b;
    a.Dispaly();
    b.Dispaly();

    return 0;
}

