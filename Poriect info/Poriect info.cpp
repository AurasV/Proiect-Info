#include <iostream>
#include <fstream>
using namespace std;
int a[50][50], x, y, i, j, n, k, st[1000], val;
ifstream f("D:\\Visual Studio repos\\Poriect info\\matrice.txt");
char p[12], s[12];
bool ok1=false, ok2=false;
//numele oraselor
const char* cities[32] = { "Shenyang","Beijing","Tianjin","Jinan","Xuzhou","Nanjing","Shanghai","Hangzhou","Huangshan","Hefei","Zhengzhou","Huashan","Wuhan","Changsha","Guanzhou","Hong Kong","Shenzen","Guilin","Nanning","Guiyang","Kunming","Chongqing","Chengdu","Xian","Pingyao","Taiyuan","Shijiazhuang","Lanzhou","Xining","Nanchang","Wuyishan","Fuzhou" };
void tipar() 
{
    int i;
    for (i = 1; i <= k; i++)
        cout << cities[i] << " ";
    cout << endl;
}
int valid(int k)
{
    //validarea lantului
    if (st[1] != x) return 0;
    for (i = 1; i <= k - 1; i++)
        if (st[i] == st[k]) return 0;
    if (k >= 2)
        for (i = 2; i <= k; i++)
            if (a[st[i - 1]][st[i]] != 1) return 0;
    return 1;
}
int main()
{
    //citirea matricii din fisier
    n = 32;
    for (i = 1; i <= 32; i++)
        for (j = 1; j <= 32; j++)
            f >> a[i][j];
    //citirea punctului de plecare respectiv de sosire
    cin >> p >> s;
    for (i = 1; i <= n; i++) 
    {
        if (cities[i] == p) 
        {
            x = i;
            ok1 = true;
        }
        if (cities[i] == s) 
        {
            y = i;
            ok2 = true;
        }
    }
    if (ok1 != true)
        cout << "nume oras plecare incorect";
    if (ok2 != true)
        cout << "nume oras sosire incorect";
    k = 2; st[1] = x; st[k] = 0;
    while (k > 0)
    {
        val = 0;
        while (val == 0 && st[k] < n)
        {
            st[k] = st[k] + 1;
            if (valid(k) == 1) val = 1;
        }
        if (val == 1)
            if (st[k] == y) tipar();
            else 
            {
                k++;
                st[k] = 0;
            }
        else k--;
    }
    return 0;
}
