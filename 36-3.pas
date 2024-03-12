var
 ox,oy:array[0..10001] of integer;
 a,v:array[-2..13,-2..13] of integer;
 n,i,j,x1,y1,x,y,bg,en,x2,y2,min:integer;
 s1,s2:string;
Begin
assign(input,'input.txt');
assign(output,'output.txt');
reset(input);
rewrite(output);
n:=8; s1:='abcdefgh12345678';
for i:=-2 to n+3 do
 for j:=-2 to n+3 do
  begin
  a[i,j]:=-1; v[i,j]:=-1;
 end;
for i:=1 to n do
 for j:=1 to n do
  begin
  a[i,j]:=0; v[i,j]:=0;
  end;
readln(s2);
for i:=1 to 2*n do
begin
if s2[1]=s1[i] then x1:=i;
if s2[4]=s1[i] then x2:=i;
if s2[2]=s1[i] then y1:=i-8;
if s2[5]=s1[i] then y2:=i-8;
end;
a[x1,y1]:=1;
bg:=1; en:=2;
ox[bg]:=x1; oy[bg]:=y1;
while (bg<en) do
begin
x:=ox[bg]; y:=oy[bg]; inc(bg);
if a[x-2,y+1]=0 then begin
                        a[x-2,y+1]:=a[x,y]+1;
                        ox[en]:=x-2;
                        oy[en]:=y+1;
                        inc(en);
                     end;
if a[x-2,y-1]=0 then begin
                        a[x-2,y-1]:=a[x,y]+1;
                        ox[en]:=x-2;
                        oy[en]:=y-1;
                        inc(en);
                     end;
if a[x-1,y+2]=0 then begin
                        a[x-1,y+2]:=a[x,y]+1;
                        ox[en]:=x-1;
                        oy[en]:=y+2;
                        inc(en);
                     end;
if a[x-1,y-2]=0 then begin
                        a[x-1,y-2]:=a[x,y]+1;
                        ox[en]:=x-1;
                        oy[en]:=y-2;
                        inc(en);
                     end;
if a[x+2,y+1]=0 then begin
                        a[x+2,y+1]:=a[x,y]+1;
                        ox[en]:=x+2;
                        oy[en]:=y+1;
                        inc(en);
                       end;
if a[x+2,y-1]=0 then begin
                        a[x+2,y-1]:=a[x,y]+1;
                        ox[en]:=x+2;
                        oy[en]:=y-1;
                        inc(en);
                     end;
if a[x+1,y+2]=0 then begin
                        a[x+1,y+2]:=a[x,y]+1;
                        ox[en]:=x+1;
                        oy[en]:=y+2;
                        inc(en);
                     end;
if a[x+1,y-2]=0 then begin
                        a[x+1,y-2]:=a[x,y]+1;
                        ox[en]:=x+1;
                        oy[en]:=y-2;
                        inc(en);
                     end;
end;
for i:=1 to sqr(n) do
begin
ox[i]:=0; oy[i]:=0;
end;
v[x2,y2]:=1;
bg:=1; en:=2;
ox[bg]:=x2; oy[bg]:=y2;
while (bg<en) do
begin
x:=ox[bg]; y:=oy[bg]; inc(bg);
if v[x-2,y+1]=0 then 
begin
v[x-2,y+1]:=v[x,y]+1;
ox[en]:=x-2;
oy[en]:=y+1;
inc(en);
end;
if v[x-2,y-1]=0 then
begin
v[x-2,y-1]:=v[x,y]+1;
ox[en]:=x-2;
oy[en]:=y-1;
inc(en);
end;
if v[x-1,y+2]=0 then 
begin
v[x-1,y+2]:=v[x,y]+1;
ox[en]:=x-1;
oy[en]:=y+2;
inc(en);
end;
if v[x-1,y-2]=0 then 
begin
v[x-1,y-2]:=v[x,y]+1;
ox[en]:=x-1;
oy[en]:=y-2;
inc(en);
end;
if v[x+2,y+1]=0 then 
begin
v[x+2,y+1]:=v[x,y]+1;
ox[en]:=x+2;
oy[en]:=y+1;
inc(en);
end;
if v[x+2,y-1]=0 then 
begin
v[x+2,y-1]:=v[x,y]+1;
ox[en]:=x+2;
oy[en]:=y-1;
inc(en);
end;
if v[x+1,y+2]=0 then 
begin
v[x+1,y+2]:=v[x,y]+1;
ox[en]:=x+1;
oy[en]:=y+2;
inc(en);
end;
if v[x+1,y-2]=0 then 
begin
v[x+1,y-2]:=v[x,y]+1;
ox[en]:=x+1;
oy[en]:=y-2;
inc(en);
end;
end;
min:=100;
for i:=1 to n do
 for j:=1 to n do
  if (a[i,j]=v[i,j]) and (min>a[i,j]) then min:=a[i,j];
if min=100 then writeln(-1) else writeln(min-1);
close(input);
close(output);
End.
