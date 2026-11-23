def FCFS(process, arrival, burst):
    n = len(process)
    ct = 0
    ttt = []
    twt = []

    pl = []
    for i in range(n):
        pd = {
            'process': process[i],
            'arrival': arrival[i],
            'burst' : burst[i]
        }
        pl.append(pd)

    pl.sort(key=lambda x:x['arrival'])

    print("Process | Arrival | Burst | Finish | Turnaround | Waiting")
    print("-" * 60)

    for p in pl:
        ct = max(ct, p['arrival'])
        ct += p['burst']
        ft = ct

        tt = ft - p['arrival']
        wt = tt - p['burst']

        ttt.append(tt)
        twt.append(wt)

        print(f" {p['process']}  |  {p['arrival']}  |  {p['burst']}  |  {ft}  | {tt} | {wt}")

    print("-"*60)
    print(f"Total turnaround time = {sum(ttt) / n} ms")
    print(f"Total waiting time = {sum(twt) / n} ms")
    print("=" * 60 + "\n")

FCFS(['P1','P2','P3','P4'], [0, 2, 4, 5], [6, 4, 2, 3])

