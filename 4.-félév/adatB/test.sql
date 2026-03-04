/*
SELECT DISTINCT NEV, GYUMOLCS
FROM (SELECT DISTINCT NEV FROM KEDVENC) NEVEK,
  (SELECT DISTINCT GYUMOLCS FROM KEDVENC) GYUM
ORDER BY 1;

SELECT DISTINCT GYUMOLCS
FROM KEDVENC
WHERE GYUMOLCS NOT IN (
  SELECT DISTINCT GYUMOLCS FROM KEDVENC WHERE NEV = 'Péter'
);

SELECT DISTINCT GYUMOLCS FROM KEDVENC
MINUS
SELECT DISTINCT GYUMOLCS FROM KEDVENC WHERE nev = 'peter';

SELECT nev, COUNT(gyumolcs) db
FROM KEDVENC
GROUP BY nev
HAVING COUNT(gyumolcs) >= 2
ORDER BY db;

SELECT DISTINCT nev
FROM KEDVENC k1
WHERE nev <> 'Ádám' AND NOT EXISTS(
  SELECT GYUMOLCS
  FROM KEDVENC
  WHERE NEV = 'Ádám' AND gyumolcs not in (
    select gyumolcs
    from kedvenc
    where nev = k1.nev
  )
);

alter session set
nls_date_format = 'YYYY.MM.DD';

select last_name, hire_date, salary 
from employees
where department_id = (
  select department_id
  from employees
  where upper(first_name) = 'ALEXANDER'
  and upper(last_name) = 'KHOO'
)
order by 3;

select last_name, job_title, 
  NVL(TO_CHAR(commission_pct * 100), 'Nem jár')
from employees join jobs using(job_id)
where last_name like 'K%';

select last_name, job_title, 
  case
    when commission_pct is null then 'nem jár'
    else to_char(commission_pct * 100)
  end
from employees join jobs using(job_id)
where last_name like 'K%';

select rpad(last_name, 10) || ': ' || 
  rpad('#', round(salary/100, 0), '#') fizetes
from employees
order by salary desc;

*/
