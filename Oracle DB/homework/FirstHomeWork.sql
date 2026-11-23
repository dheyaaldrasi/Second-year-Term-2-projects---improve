select * from STUDENT;
begin
    for student in (select name from STUDENT)loop
    dbms_output.put_line('name: ' ||  STUDENT.name);
    end loop;
    end;
    /
