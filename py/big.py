def gig(g):

    f = open("d:/{}gB.txt".format(g), 'w')

    for gB in range(1024 * g):
        for mB in range(1023):
            for kB in range(1024):
                f.write("a")
        for i in range(1022):
            f.write("a")
        f.write("\n")

        print("{}%".format(round((gB + 1) / (g * 1024) * 100, 6)))

    f.close()

# gig(20)