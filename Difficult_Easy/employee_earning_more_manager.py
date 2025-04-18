import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    merged = employee.merge(employee, left_on='managerId', right_on='id', suffixes=("","_manager"))
    df_emp_more = merged.loc[merged['salary']>merged['salary_manager']]
    return df_emp_more[['name']].rename(columns={'name':'Employee'})