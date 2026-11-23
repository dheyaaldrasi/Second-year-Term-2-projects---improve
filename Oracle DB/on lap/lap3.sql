-- declare
--     i number:=5;
--     begin
--     while i >= 1 loop
--     dbms_output.put_line(i);
--     i:= i - 1;
--     end loop;
-- end;
-- /


-- begin
--     for i in 1 ..10 loop
--     DBMS_OUTPUT.PUT_LINE(i);
--     end loop;
--     end;
--     /


-- begin
--     for i in reverse 1 .. 10  loop
--     DBMS_OUTPUT.PUT_LINE(i);
--     end loop;
--     end;
--     /

    -- select * from STUDENT;

-- begin
--     for i in (select * from STUDENT) loop
--     DBMS_OUTPUT.PUT_LINE('The name is: ' || i.name || ' The ID is: ' || i.id);
--     end loop;
--     end;
--     /

-- select * from STUDENT;
-- select * from EMPLOYEE;

-- create table student2(
--     id number,
--     names varchar(50)
-- );


-- begin
--     for i in (select * from STUDENT where id = 1) loop
--     insert into STUDENT2 values(i.id,i.name);
--     end loop;
--     end;
--     /


-- select * from STUDENT2;


