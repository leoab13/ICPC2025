#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool corner = false;
bool posibleCorner = false;


ll int getX(vector<pair<ll int, ll int>> &k, ll int &minX,ll int &maxX)
{
    minX = k[0].first;
    maxX = k[0].first;
    for(auto c : k)
    {
        if(c.first < minX) minX = c.first;
        if(c.first > maxX) maxX = c.first;
    }

    return maxX - minX;
}

ll int getY(vector<pair<ll int, ll int>> &k, ll int &minY, ll int &maxY)
{
    minY = k[0].second;
    maxY = k[0].second;
    for(auto c : k)
    {
        if(c.second < minY) minY = c.second;
        if(c.second > maxY) maxY = c.second;
    }
    return maxY - minY;
}

void isPosibletoMakeSquare(vector<pair<ll int, ll int>> &k, ll int &minX, ll int &maxX, ll int &minY, ll int &maxY, bool &xory)
{
    for(auto c : k)
    {
        ll int a = c.first;
        ll int b = c.second;
        if( (a == minX || a == maxX) && ( ( b - 1 == minY || b + 1 == minY ) || (b - 1 == maxY || b + 1 == maxY) ) )
        {   xory = false;//falso = el max esta en X y se tiene que acercar en Y
            posibleCorner = true;
            break;
        }
        else if ( ( b == minY || b == maxY ) && ( (a - 1 == minX || a + 1 == minX) || ( a - 1 == maxX || a + 1 == maxX) ) )
        {
            xory = true;// true el max esta en Y y hay que acercar X
            posibleCorner = true;
            break;
        }
    }
}

void isCorner(vector<pair<ll int, ll int>> &k, ll int &minX, ll int &maxX, ll int &minY, ll int &maxY)
{
    for(auto c : k)
    {
        if( ( c.first == minX && c.second == minY ) ||
            ( c.first == minX && c.second == maxY ) ||
            ( c.first == maxX && c.second == minY ) ||
            ( c.first == maxX && c.second == maxY ))
        {
            corner = true;
            break;
        }
    }
}

ll int solution(vector<pair<ll int, ll int>> &kings,ll int &k)
{
    int movesX = k /2;
    int movesY = k - movesX;
    ll int minX, maxX, minY, maxY = 0;
    ll x = getX(kings,minX,maxX) + 1;
    ll y = getY(kings,minY,maxY) + 1;
    bool xory = false;
    //imprime tamano de los lados
    //cout << x << " " << y << endl;
    isCorner(kings,minX,maxX,minY,maxY);
    if(corner == false) isPosibletoMakeSquare(kings,minX,maxX,minY,maxY,xory);
    //posibles casos, es un cuadrado o un rectangulo
    // casos de cuadrado : tiene esquinas, no tiene esquinas
    // si un cuadrado no tiene esquinas : se puede hacer una esquina o no

    // casos de un rectangulo
    // tiene esquinas
    // no tiene esquinas: se puede hacer una esquina o no
    // si se puede hacer esquina verificar si hay que incrementar en X o Y para hacer esquina, de ahi aumentar como si fuera un cuadrado
    // si no se puede hacer esquina sumar el maximo de moviemientos posibles al lado mas grande y el menos al menor

    if( k == 1)
    {
        ll mn = min(x,y);
        ll mx = max(x,y);
        mn++;
        return mn * mx;
    }
    //cadena para debuguear a que caso entra
    //string dbg= "";
    if( (x == y))
    {
        if(corner)
        {
            x+= k;
            y+= k;
            //dbg = "cuadrado con esquina";
        }  
        else
        {
            if(posibleCorner)
            {
                x++;
                k--;
                x+=k;
                y+=k;
                //dbg = "cuadrado con posible esquina";
            }
            else
            {
                x+=movesX;
                y+=movesY;
                //dbg = "cuadrado sin esquinas posibles";
            }
        }
    }
    else
    {
        if(corner)
        {
            x+=k;
            y+=k;
            //dbg = "rectangulo con esquina";
        }
        else
        {
            if(posibleCorner)
            {
                if(xory == false)// incrementar en Y
                {
                    y++;
                    k--;
                    //dbg = "rectangulo con posible esquina sumando en Y";
                }
                else // incrementar en X
                {
                    x++;
                    k--;
                    //dbg = "rectangulo con posible esquina sumando en X";
                }
                y+=k;
                x+=k;
            }
            else
            {
                ll int maxv, minv;// optimizar mas movimientos hacia el lado que es mas grande
                maxv = max(x , y) + max(movesX , movesY);
                minv = min(x , y) + min(movesX , movesY);
                x = maxv;
                y = minv;
                //dbg = "rectangulo sin posibles esquinas";
            }
        }
    }
    //imprime cadena de debug a que caso entro
    //cout << dbg << endl;
    //imprime los lados finales
    //cout << k << " " << x << " " << y << endl;
    return x * y;
}

int main()
{
    ll int n,k;
    cin >> n >> k;
    vector<pair<ll int, ll int>> kings;
    for(int i = 0; i < n; i ++)
    {
        ll int x,y;
        cin >> x >> y;
        auto tmp = make_pair(x,(y * -1));
        kings.push_back(tmp);
    }
    if(n == 1) {cout << 1 << endl; return 0;}
    cout << solution(kings,k);
    return 0;
}
/*
CASOS DE PRUEBA PROBLEMA K:
CASOS DE LA HOJA:
INPUT
4 1
1 -1
-2 -1
0 -2
0 0

OUTPUT
16

INPUT
2 3
1 1
-1 0

OUTPUT
30

INPUT
2 99999
0 0
1 1
OUTPUT
10000200001

CASOS NO PREVISTOS
//Cuadrado pero no tiene esquinas, pero uno de los reyes puede tomar esquina
- X -
X - X
- X -
INPUT:
4 3
0 1
1 0
1 2
2 1

OUTPUT:
30

//Rectangulo sin esquinas, ninguno de los reyes puede tomar esquina
- - - - - - X - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - -
X - - - - - - - - - - - - - - - - - - - - - - X
- - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - X - - - - - - - - - - -
INPUT:
4 2
0 20
3 0
3 23
5 11

OUTPUT:
175


Rectangulo sin esquinas, se puede volver esquina aumentando en Y
- X - - -
- - - - -
X - - - X
- - - - -
- - - - -
- - X - -
INPUT:
4 1
0 1
2 0
2 4
5 2

OUTPUT:
36

Rectangulo sin esquinas, se puede volver esquina aumentando en Y
- - X - - -
- - - - - X
X - - - - -
- - - X - -


INPUT:
4 1
0 1
2 3
3 0
5 2


OUTPUT:
30


//Cuadrado sin esquinas pero ninguno de los reyes puede tomar esquina
- - - X - - -
- - - - - - -
X - - - - - X
- - - - - - -
- - - X - - -

INPUT:
4 1
0 3
2 0
2 6
4 3

OUTPUT:
40

*/