def srtf(processes, arrival_time, burst_time):
    n = len(processes)
    remaining_time = list(burst_time) 
    completed_processes = []
    current_time = 0.0
    total_waiting_time = 0.0
    total_turnaround_time = 0.0
    
    print("=== (Gantt Chart) ===")
    
    while len(completed_processes) < n:
        idx = None
        
        for i in range(n):
            if arrival_time[i] <= current_time and (processes[i] not in completed_processes):
                
                if idx is None:
                    idx = i
                
                elif remaining_time[i] < remaining_time[idx]:
                    idx = i
                
                elif remaining_time[i] == remaining_time[idx]:
                    if arrival_time[i] < arrival_time[idx]:
                        idx = i
                    
        if idx is not None:
            print(f"| {processes[idx]}({int(current_time)}-{int(current_time+1)}) ", end="")
            remaining_time[idx] -= 1
            current_time += 1
            
            if remaining_time[idx] == 0:
                finish_time = current_time
                turnaround_time = finish_time - arrival_time[idx]
                total_turnaround_time += turnaround_time
                
                waiting_time = turnaround_time - burst_time[idx]
                total_waiting_time += waiting_time
                completed_processes.append(processes[idx])
        else:
            print("| IDLE ", end="")
            current_time += 1
            
    print("|")
    
    average_waiting_time = total_waiting_time / n
    average_turnaround_time = total_turnaround_time / n
    print(f"\nAverage Waiting Time (AWT) = {average_waiting_time} ms")
    print(f"Average Turnaround Time (ATAT) = {average_turnaround_time} ms")

if __name__ == "__main__":
    process_names = ["P1", "P2", "P3", "P4"]
    arrival_times = [0.0, 2.2, 4.0, 5.0]
    burst_times   = [7, 4, 1, 4]
    
    srtf(process_names, arrival_times, burst_times)
