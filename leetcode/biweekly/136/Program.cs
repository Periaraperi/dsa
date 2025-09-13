if (args.Length != 1) 
{
    Console.WriteLine("expected name of problem, [A, B, C, or D], as the only argument to the program");
    return;
}

switch(args[0])
{
    case "A":
        var a = new A();
        int n = 4;
        int[][] pick = [[0,0],[1,0],[1,0],[2,1],[2,1],[2,0]];
        Console.WriteLine("{0}", a.WinningPlayerCount(n, pick));
        break;
    case "B":
        var b = new B();
        
        List<int[][]> grids = new();
        grids.AddRange(
            [[1,0,0],[0,0,0],[0,0,1]],
            [[0,1],[0,1],[0,0]]);
        foreach (var g in grids) {
            Console.WriteLine(b.MinFlips(g));
        }
        break;
    case "C":
        throw new NotImplementedException();
        //break;
    case "D":
        throw new NotImplementedException();
        //break;
    default:
        Console.WriteLine("expected name of problem, [A, B, C, or D], as the only argument to the program");
        break;
}
