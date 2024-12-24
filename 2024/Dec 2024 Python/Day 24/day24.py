from collections import deque


class FunctionToSolve:
    def __init__(self, name1: str, name2: str, name3: str, fn: str):
        self.name1 = name1
        self.name2 = name2
        self.name3 = name3
        self.fn = fn
        self.is_evaluted = False

    def __str__(self):
        return f'{self.name1} {self.fn} {self.name2} -> {self.name3}'

    def can_evaluate(self, d: dict) -> bool:
        is_n1_in_dict = self.name1 in d
        is_n2_in_dict = self.name2 in d
        return is_n1_in_dict and is_n2_in_dict

    def evalue(self, d: dict):
        match self.fn:
            case "AND":
                if d[self.name1] == 0 or d[self.name2] == 0:
                    d[self.name3] = 0
                else:
                    d[self.name3] = 1
            case "OR":
                if d[self.name1] == 1 or d[self.name2] == 1:
                    d[self.name3] = 1
                else:
                    d[self.name3] = 0
            case "XOR":
                if d[self.name1] == d[self.name2]:
                    d[self.name3] = 0
                else:
                    d[self.name3] = 1


def main():

    file_name = "../textfiles/day24test.txt"
    part_one(file_name)


def part_one(file_name):
    bits = dict()
    with open(file=file_name, encoding="utf8") as f:
        lines = f.read().splitlines()
        is_known = True
        notEvalutedFunctions: deque = deque([])
        for line in lines:
            if line.strip() == "":
                is_known = False
                continue
            if not is_known:
                n1 = ""
                n2 = ""
                n3 = ""
                fn = ""
                # pt1 = line.split("-")[0].strip()
                n1 = line.split(" ")[0].strip()
                fn = line.split(" ")[1].strip()
                n2 = line.split(" ")[2].strip()
                n3 = line.split(">")[1].strip()
                # print("n1:", n1)
                # print("fn:", fn)
                # print("n2:", n2)
                # print("n3:", n3)
                notEvalutedFunctions.append(FunctionToSolve(
                    name1=n1, name2=n2, name3=n3, fn=fn))

            else:
                name = line.split(":")[0]
                value = int(line.split(":")[1])
                bits[name] = value
        while notEvalutedFunctions:
            current_function_to_solve: FunctionToSolve = notEvalutedFunctions.popleft()
            # print(current_function_to_solve)
            if current_function_to_solve.can_evaluate(bits):
                # i can still solve
                current_function_to_solve.evalue(bits)
            else:
                # i still don't know how to solve
                notEvalutedFunctions.append(current_function_to_solve)

        sortedkeys = sorted(bits, key=str.lower)
        # print(sortedkeys)
        s1 = ""
        i = 0
        print("z"+str(i).rjust(2, '0'))
        while "z"+str(i).rjust(2, '0') in bits:
            s1 = str(bits["z"+str(i).rjust(2, '0')]) + s1
            i += 1
        # print(s1)
        print("Day 24 part one:", int(s1, base=2))


main()
