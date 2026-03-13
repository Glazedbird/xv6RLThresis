import pandas as pd

rows = []

input_prefix = "./rawdata/"
output_prefix = "./data/"
with open(input_prefix + "log.txt") as f:
    for line in f:
        if line.startswith("SUMMARY"):
            p = line.strip().split(",")

            rows.append({
                "mode": int(p[1]),
                "n": int(p[2]),
                "avg_turnaround": int(p[3]),
                "avg_response": int(p[4]),
                "avg_wait": int(p[5]),
                "avg_run": int(p[6]),
                "avg_sleep": int(p[7]),
                "avg_sched": int(p[8]),
                "total_turnaround": int(p[9]),
                "total_response": int(p[10]),
                "total_wait": int(p[11]),
                "total_run": int(p[12]),
                "total_sleep": int(p[13]),
                "total_sched": int(p[14]),
            })

df = pd.DataFrame(rows)
df.to_csv(output_prefix + "data.csv", index=False)
