#include <iostream>
#include <fstream>
using namespace std;
int a[50][50], x, y, i, j, n, k, st[1000], val;
string p, s, q;
bool ok1 = false, ok2 = false;
//the file location must be changed depending on where you stored it!!!
ifstream f("D:\\Visual Studio repos\\Poriect info\\matrice.txt");
//name of cities
const char* cities[33] = { "shabdajdhajhhajkhdaj","Shenyang","Beijing","Tianjin","Jinan","Xuzhou","Nanjing","Shanghai","Hangzhou","Huangshan","Hefei","Zhengzhou","Huashan","Wuhan","Changsha","Guanzhou","Hong Kong","Shenzen","Guilin","Nanning","Guiyang","Kunming","Chongqing","Chengdu","Xian","Pingyao","Taiyuan","Shijiazhuang","Lanzhou","Xining","Nanchang","Wuyishan","Fuzhou" };
//writing the possible routes
void tipar(){
    int i;
    for (i = 1; i <= k; i++)
        cout << cities[st[i]] << " ";
    cout << endl;}
//validating the routes
int valid(int k){
    if (st[1] != x) return 0;
    for (i = 1; i <= k - 1; i++)
        if (st[i] == st[k]) return 0;
    if (k >= 2)
        for (i = 2; i <= k; i++)
            if (a[st[i - 1]][st[i]] != 1) return 0;
    return 1;}
//main function
int main(){
    //reading the matrix from file
    n = 32;
    for (i = 1; i <= 32; i++)
        for (j = 1; j <= 32; j++)
            f >> a[i][j];
    //reading starting and arrival points
    cin >> p >> s;
    //checking if the names are correct
    for (i = 0; i <= 32; i++)
    {
        q = cities[i];
        if (q == p)
        {
            x = i;
            ok1 = true;
        }
        if (q == s)
        {
            y = i;
            ok2 = true;
        }
    }
    //if the names aren't correct the program tells the user which one is incorrect
    if (ok1 != true)
        cout << "nume oras plecare incorect"<<endl;
    if (ok2 != true)
        cout << "nume oras sosire incorect";
    //if any of the names are incorrect the program stops
    if (ok1 != true || ok2 != true)
        return 0;
    //finding the routes you can take
    k = 2; st[1] = x; st[k] = 0;
    while (k > 0){
        val = 0;
        while (val == 0 && st[k] <= n){
            st[k] = st[k] + 1;
            if (valid(k) == 1) val = 1;}
        if (val == 1)
            if (st[k] == y) tipar();
            else {
                k++;
                st[k] = 0;}
        else k--;}
    return 0;}
