def main():

    partOne("../textfile/day4final.txt")
    partTwo("../textfile/day4final.txt")

def partOne(fileName):

    with open(fileName,encoding="utf-8") as f:
        d = dict()
        cnt =0
        for line in f.readlines():
            keys = [x.strip() for  x in line.split(" ")]
            for k in keys:
                if ':' in k:
                    k1,v1 = k.split(':')
                    d[k1] = v1
                else:
                    if isValidPartOne(d):
                        cnt+=1

                    d =dict()
                #print(k)
        if isValidPartOne(d):
            cnt += 1
        print("Day 4 Part One:",cnt)



def isValidPartOne(d):


    # byr (Birth Year) - four digits; at least 1920 and at most 2002.
        if "byr" not in d:
            return False

    # iyr (Issue Year) - four digits; at least 2010 and at most 2020.
        if "iyr" not in d:
            return False

    # eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
        if "eyr" not in d:
            return False

    # hgt (Height) - a number followed by either cm or in:
    # If cm, the number must be at least 150 and at most 193.
    # If in, the number must be at least 59 and at most 76.

        if "hgt" not in d:
            return False



    # hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
        if "hcl" not in d:
            return False
        possible_eye_colors = ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]

        # ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
        if "ecl" not in d:
            return False

    # pid (Passport ID) - a nine-digit number, including leading zeroes.
        if "pid" not in d:
            return False

        return True

def partTwo(fileName):

    with open(fileName,encoding="utf-8") as f:
        d = dict()
        cnt =0
        for line in f.readlines():
            keys = [x.strip() for  x in line.split(" ")]
            for k in keys:
                if ':' in k:
                    k1,v1 = k.split(':')
                    d[k1] = v1
                else:
                    if isValidPartTwo(d):
                        cnt+=1

                    d =dict()
                #print(k)
        if isValidPartTwo(d):
            cnt += 1
        print("Day 4 Part One:",cnt)



def isValidPartTwo(d):

    # byr (Birth Year) - four digits; at least 1920 and at most 2002.
        if "byr" not in d:
            return False
        else:
            yearNumber = int(d["byr"])
            if yearNumber < 1920 or yearNumber > 2002:
                #print("year number is wrong:",yearNumber)
                return False




    # iyr (Issue Year) - four digits; at least 2010 and at most 2020.
        if "iyr" not in d:
            return False
        else:


            # if len(d["iyr"]) != 4:
            #   return False

            yearNumber = int(d["iyr"])

            if yearNumber < 2010 or yearNumber > 2020:
                #print("issue year number is wrong",yearNumber)
                return False

    # eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
        if "eyr" not in d:
            return False
        else:


            if len(d["eyr"]) != 4:
              return False

            yearNumber = int(d["eyr"])

            if yearNumber < 2020 or yearNumber > 2030:
                #print("Expiration year number is wrong",yearNumber)
                return False

    # hgt (Height) - a number followed by either cm or in:
    # If cm, the number must be at least 150 and at most 193.
    # If in, the number must be at least 59 and at most 76.

        if "hgt" not in d:
            return False
        else:
            #print(d["hgt"])

            val = d["hgt"][0:-2]
            units   = d["hgt"][-2:]

            #print(val,units)

            if units == "in":

                if int(val) <  59 or int(val) >76:
                    #print("bad value (in)",d["hgt"])
                    return False

            elif units == "cm":
                if int(val) <  150 or int(val) >193:
                   # print("bad value (cm)",d["hgt"])
                    return False
            else:
                #print("units wrong",d["hgt"])
                return False




    # hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
        if "hcl" not in d:
            return False
        else:

            hair_color =  d["hcl"]
            #print(hair_color)

            if hair_color[0] == '#' and len(hair_color) == 7:
                for h in hair_color[1:]:
                    if not str.isnumeric(h) and h not in ['a','b','c','d','e','f']:
                        #print("not a hair color",hair_color)
                        return False
            else:
                #print("not a hair color in else",hair_color)
                return False


        # ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
        possible_eye_colors = ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]

        if "ecl" not in d:
            return False
        else:
                #print(d['ecl'])
                eye_color =  d["ecl"]
                #print(eye_color)
                if eye_color not in possible_eye_colors or len(eye_color) != 3:
                    #print("bad eye color",eye_color)
                    return False



    # pid (Passport ID) - a nine-digit number, including leading zeroes.
        if "pid" not in d:
            return False
        else:
                passport_id =  d["pid"].strip()
                #print("pid:",passport_id)
                if len(passport_id) != 9 or not str.isdigit(passport_id):
                    #print("pid:",passport_id,"is not valid")
                    return False
        #print(d["hgt"])
        return True





main()