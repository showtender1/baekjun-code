int n = int.Parse(Console.ReadLine());
int k = int.Parse(Console.ReadLine());

bool[,] arr = new bool[n + 1, n + 1];
for (int i = 0; i < k; i++)
{
    string[] arr2 = Console.ReadLine().Split();
    int a = int.Parse(arr2[0]);
    int b = int.Parse(arr2[1]);
    arr[a, b] = true;
}

int l = int.Parse(Console.ReadLine());

int[] arr3 = new int[l];
char[] arr4 = new char[l];
for (int i = 0; i < l; i++)
{
    string[] arr5 = Console.ReadLine().Split();
    arr3[i] = int.Parse(arr5[0]);
    arr4[i] = arr5[1][0];
}

Queue<(int, int)> arr6 = new Queue<(int, int)>();
arr6.Enqueue((1, 1));
HashSet<(int, int)> arr7 = new HashSet<(int, int)>();
arr7.Add((1, 1));
int t = 0;
int d = 0;
int[,] arr8 = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

(int hr, int hc) = (1, 1);
int idx = 0;

while (true)
{
    t++;

    hr += arr8[d, 0];
    hc += arr8[d, 1];

    if (hr <= 0 || hr > n || hc <= 0 || hc > n || arr7.Contains((hr, hc)))
    {
        Console.WriteLine(t);
        break;
    }

    arr6.Enqueue((hr, hc));
    arr7.Add((hr, hc));

    if (arr[hr, hc])
    {
        arr[hr, hc] = false;
    }
    else
    {
        var tail = arr6.Dequeue();
        arr7.Remove(tail);
    }

    if (idx < l && arr3[idx] == t)
    {
        char c = arr4[idx];
        if (c == 'L')
        {
            d = (d + 3) % 4;
        }
        else if (c == 'D')
        {
            d = (d + 1) % 4;
        }
        idx++;
    }
}
