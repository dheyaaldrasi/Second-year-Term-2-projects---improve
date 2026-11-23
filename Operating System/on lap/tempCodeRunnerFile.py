        else:
            upcoming_arrivals = []
            for i in range(n):
                if processes[i] not in completed_processes:
                    upcoming_arrivals.append(arrival_time[i])
            if upcoming_arrivals:
                current_time = min(upcoming_arrivals)