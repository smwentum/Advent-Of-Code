# idea make an adjacency list
def main():

    file_name = "../textfiles/day23final.txt"
    part_one(file_name)
    file_name = "../textfiles/day23final.txt"
    part_two(file_name)


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


# took this from wikipedia  Bron–Kerbosch
# https://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm
# algorithm BronKerbosch1(R, P, X) is
#     if P and X are both empty then
#         report R as a maximal clique
#     for each vertex v in P do
#         BronKerbosch1(R ⋃ {v}, P ⋂ N(v), X ⋂ N(v))
#         P := P \ {v}
#         X := X ⋃ {v}

def BronKerbosch(r: set, p: set, x: set, d: dict, c: list):
    if len(p) == 0 and len(x) == 0:
        if len(r) > 2:
           # print(c)
            c.append(sorted(r))
            return
    for v in p.union(set([])):
        if p != None:
            BronKerbosch(r.union(set([v])),
                         p.intersection(d[v]),
                         x.intersection(d[v]), d, c)
            p.remove(v)
            x.add(v)


def part_two(file_name):
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
        r = set()
        p = set()
        for k, _ in graph.items():
            p.add(k)
        x = set()
        c = []
        BronKerbosch(r, p, x, graph, c)
        # print(c)
        mx = 0
        str1 = ""
        for c1 in c:
            if len(c1) > mx:
                # print(c1)
                mx = len(c1)
                str1 = ",".join(x for x in c1)

        # s = set()
        # lsts = set()
        # # print(graph)
        # for k, _ in graph.items():
        #     for m in graph[k]:
        #         for n in graph[m]:
        #             if k in graph[n]:
        #                 current = [k, m, n]
        #                 current.sort()
        #                 lsts.add((current[0], current[1], current[2]))

        # for l in lsts:
        #     for m in l:
        #         if m.startswith("t"):
        #             cnt += 1
        #             break
        print("Day 23 part 2:", str1)

        # print(graph)


main()
