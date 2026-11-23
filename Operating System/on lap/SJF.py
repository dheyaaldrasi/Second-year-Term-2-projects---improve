def sjf_non_preemptive(processes, arrival_time, burst_time):
    n = len(processes)
    completed_processes = []
    current_time = 0.0

    total_waiting_time = 0.0
    total_turnaround_time = 0.0

    print("=== (Gantt Chart) ===")

    for count in range(n):
        idx = None # active process

        for i in range(n):
            if arrival_time[i] <= current_time and (processes[i] not in completed_processes):
                if idx is None:  # noqa: SIM114
                    idx = i

                elif burst_time[i] < burst_time[idx]:
                    idx = i

                elif burst_time[i] == burst_time[idx]:  # noqa: SIM102
                    if arrival_time[i] < arrival_time[idx]:
                        idx = i

        if idx is not None:
            start_time = current_time
            finish_time = current_time + burst_time[idx]

            turnaround_time = finish_time - arrival_time[idx]
            total_turnaround_time += turnaround_time

            waiting_time = turnaround_time - burst_time[idx]
            total_waiting_time += waiting_time

            print(
                f"| {processes[idx]} ({int(start_time)} -> {int(finish_time)}) ", end=""
            )

            current_time = finish_time
            completed_processes.append(processes[idx])

# اضافة شرط القفز الى اقرب موعد
        else:
            upcoming_arrivals = []
            for i in range(n):
                if processes[i] not in completed_processes:
                    upcoming_arrivals.append(arrival_time[i])
            if upcoming_arrivals:
                current_time = min(upcoming_arrivals)


    print("|")

    average_waiting_time = total_waiting_time / n
    average_turnaround_time = total_turnaround_time / n

    print(f"\nAverage Waiting Time (AWT) = {average_waiting_time} ms")
    print(f"Average Turnaround Time (ATT) = {average_turnaround_time} ms")


if __name__ == "__main__":
    process_names = ["P1", "P2", "P3", "P4"]
    arrival_times = [0.0, 2.0, 4.0, 5.0]
    burst_times = [7, 4, 1, 4]

    sjf_non_preemptive(process_names, arrival_times, burst_times)
