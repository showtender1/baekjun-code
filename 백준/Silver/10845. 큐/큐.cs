int n = int.Parse(Console.ReadLine());
Queue<int> arr = new Queue<int>();
int last = -1;
List<string> output = new List<string>();

for (int i = 0; i < n; i++)
{
    string[] arr2 = Console.ReadLine().Split();

    if (arr2[0] == "push")
    {
        int x = int.Parse(arr2[1]);
        arr.Enqueue(x);
        last = x;
    }
    else if (arr2[0] == "pop")
    {
        if (arr.Count > 0)
        {
            output.Add(arr.Dequeue().ToString());
        }
        else
        {
            output.Add("-1");
        }
    }
    else if (arr2[0] == "size")
    {
        output.Add(arr.Count.ToString());
    }
    else if (arr2[0] == "empty")
    {
        output.Add(arr.Count == 0 ? "1" : "0");
    }
    else if (arr2[0] == "front")
    {
        if (arr.Count > 0)
        {
            output.Add(arr.Peek().ToString());
        }
        else
        {
            output.Add("-1");
        }
    }
    else if (arr2[0] == "back")
    {
        if (arr.Count > 0)
        {
            output.Add(last.ToString());
        }
        else
        {
            output.Add("-1");
        }
    }
}

Console.WriteLine(string.Join("\n", output));
