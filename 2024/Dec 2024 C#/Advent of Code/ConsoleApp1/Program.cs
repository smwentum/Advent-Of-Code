namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<int> l1 = new List<int>();
            List<int> l2 = new List<int>();
            //Console.WriteLine(Environment.CurrentDirectory);
            List<string> lines = File.ReadAllLines("C:\\Users\\Sai Wentum\\Documents\\Programming Projects\\Advent Of Code\\2024\\Dec 2024 C#\\Advent of Code\\ConsoleApp1\\day1.txt").ToList();

            foreach (string line in lines)
            {
                l1.Add( int.Parse(line.Split(" ", StringSplitOptions.RemoveEmptyEntries)[0]));
                l2.Add(int.Parse(line.Split(" ", StringSplitOptions.RemoveEmptyEntries)[1]));
            }

            GetDiffernce(l1, l2);
        }

        static void GetDiffernce(List<int> l1, List<int> l2)
        { 
            l1.Sort();
            l2.Sort();
            int sum = 0;
            for (int i = 0; i < l1.Count && i < l2.Count; i++)
            {
                sum += Math.Abs(l1[i] - l2[i]);
            }
            Console.WriteLine($"Day One part one {sum}");
        }
    }
}
