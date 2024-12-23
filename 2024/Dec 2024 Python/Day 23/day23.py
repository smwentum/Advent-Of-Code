# idea make an adjacency list
def main():

    file_name = "../textfiles/day23final.txt"
    part_one(file_name)


def part_one(file_name):
    with open(file=file_name, encoding="utf8") as f:
        lines = f.read().splitlines()
        graph = dict()

        for line in lines:
            a, b = [x.strip() for x in line.split("-")]
            if a not in graph:
                graph[a] = []
            if b not in graph:
                graph[b] = []
            graph[a].append(b)
            graph[b].append(a)
        s = set()
        lsts = set()
        # print(graph)
        for k, _ in graph.items():
            for m in graph[k]:
                for n in graph[m]:
                    if k in graph[n]:
                        current = [k, m, n]
                        current.sort()
                        lsts.add((current[0], current[1], current[2]))

        cnt = 0
        for l in lsts:
            for m in l:
                if m.startswith("t"):
                    cnt += 1
                    break
        print("Day 23 part 1:", cnt)

        # print(graph)


main()
