def maxPresentations(scheduleStart, scheduleEnd):
    n = len(scheduleStart)

    # Create a list of tuples (start time, end time, presentation index).
    presentations = [(scheduleStart[i], scheduleEnd[i], i) for i in range(n)]

    # Sort the presentations by their end times.
    presentations.sort(key=lambda x: x[1])

    max_attended = 0
    prev_end_time = -1

    for presentation in presentations:
        start_time, end_time, _ = presentation
        if start_time >= prev_end_time:
            max_attended += 1
            prev_end_time = end_time

    return max_attended

# Read input
n = int(input())
scheduleStart = []
for _ in range(n):
    start_time = int(input())
    scheduleStart.append(start_time)

n = int(input())
scheduleEnd = []
for _ in range(n):
    end_time = int(input())
    scheduleEnd.append(end_time)

# Call the function
result = maxPresentations(scheduleStart, scheduleEnd)
print(result)
