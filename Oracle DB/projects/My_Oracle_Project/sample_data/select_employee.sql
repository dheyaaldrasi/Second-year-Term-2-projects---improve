select
    employee_id as "EmployeeID",
    last_name || ', ' || first_name as "Employee Name",
    salary as "Montholy Sal",
    (salary * 0.15) * 12 as "Annual Increase Amount",
    ((salary * 0.15) * 12) + nvl(commission_pct, 0) as "Total Expected Income",
    NVL2(commission_pct, 'Commission Eligible', 'Salaried Only') as "Commission Status"
from EMPLOYEE;

SELECT
    employee_id AS "Employee ID",
    last_name || ', ' || first_name AS "Employee Name",
    salary AS "Monthly Salary",
    (salary * 0.15) * 12 AS "Annual Increase Amount",
    (salary * 1.15 * 12) + (salary * 12 * NVL(commission_pct, 0)) AS "Total Expected Income",
    NVL2(commission_pct, 'Commission Eligible', 'Salaried Only') AS "Commission Status"
FROM employee;