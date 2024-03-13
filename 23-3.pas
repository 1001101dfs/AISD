var a,n,k,s:int64;
begin
  readln(n);
  if n mod 2=0 then
    begin
      k:=n div 2;
      s:=k*(k+1)*(4*k+1)div 2;
    end
    else
    begin
      k:=(n-1) div 2;
      s:=(k+1)*(4*k*k+7*k+2)div 2
    end;
    writeln(s);
end.
