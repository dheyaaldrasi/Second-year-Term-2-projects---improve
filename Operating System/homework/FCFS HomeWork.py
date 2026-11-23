def calculate_fcfs(processes, arrival_time, burst_time):
    n = len(processes)
    current_time = 0
    total_turnaround = []
    total_waiting = []

    if len(processes) != len(arrival_time) or len(processes) != len(burst_time):
        print("Error: عدد العمليات يجب أن يكون متساويًا مع عدد أوقات الوصول وأوقات التنفيذ.")
        return

    processesList = []
    for i in range(n):
        processesData = {
            'process': processes[i],
            'arrival': arrival_time[i],
            'burst': burst_time[i]
        }
        processesList.append(processesData)
    
    processesList.sort(key=lambda x: x['arrival'])

    print("Process | Arrival | Burst | Finish | Turnaround | Waiting")
    print("-" * 60)

    for p in processesList:

        current_time = max(current_time, p['arrival'])
        current_time += p['burst']
        finish_time = current_time 


        turnaround = finish_time - p['arrival']
        waiting = turnaround - p['burst']


        total_turnaround.append(turnaround)
        total_waiting.append(waiting)

        print(f"  {p['process']}    |    {p['arrival']}    |   {p['burst']}   |   {finish_time}    |     {turnaround}      |    {waiting}")


    print("-" * 60)
    print(f"Average Turnaround Time = {sum(total_turnaround) / n:.2f} ms")
    print(f"Average Waiting Time = {sum(total_waiting) / n:.2f} ms")
    print("=" * 60 + "\n")


print("--- الحالة الأولى (المهمة الطويلة P1 تصل أولاً) ---")
calculate_fcfs(['P1', 'P2', 'P3', 'P4'], [0, 2, 4, 5], [6, 4, 2, 3])

print("--- الحالة الثانية (المهام القصيرة تصل أولاً - Convoy Effect) ---")
calculate_fcfs(['P2', 'P3', 'P1', 'P4'], [0, 2, 4, 5], [2, 3, 4, 6])
