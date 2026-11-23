declare
    v number := 5;
begin
    if v > 6 then
    dbms_output.put_line('Diaa Al-Drasi');
    else 
    dbms_output.put_line('low number');
    end if;
    end;
    /

    select * from STUDENT;

insert into STUDENT values(50, 'Amro Damag');



declare
    degree int := 85;
    begin
    if degree > 100 then
    dbms_output.put_line('the degre can not be bigger than 100');
    elsif degree >= 90 and degree <= 100 then
    dbms_output.put_line('excellent');
    elsif degree >= 80 and degree <= 89 then
    dbms_output.put_line('very good');
    elsif degree >= 60 and degree <= 79 then
    dbms_output.put_line('good');
    elsif degree >= 50 and degree <= 59 then
    dbms_output.put_line('try hard');
    elsif degree >= 0 and degree <= 49 then
    dbms_output.put_line('fail');
    end if;
    end;
/


commit;

create table test(
    id int,
    names varchar(50),
    degree int
);

insert into test values(1, 'Diaa Al-Drasi', 98);

select * from test;

declare
    v_degree int;
    begin
    select degree into v_degree from test;
    if v_degree > 100 then
    dbms_output.put_line('the degre can not be bigger than 100');
    elsif v_degree >= 90 and v_degree <= 100 then
    dbms_output.put_line('excellent');
    elsif v_degree >= 80 and v_degree <= 89 then
    dbms_output.put_line('very good');
    elsif v_degree >= 60 and v_degree <= 79 then
    dbms_output.put_line('good');
    elsif v_degree >= 50 and v_degree <= 59 then
    dbms_output.put_line('try hard');
    elsif v_degree >= 0 and v_degree <= 49 then
    dbms_output.put_line('fail');
    end if;
    end;
/


