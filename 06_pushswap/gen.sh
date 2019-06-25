num=$1
num=$num-1
./push_swap `ruby -e "puts (0..$num).to_a.shuffle.join(' ')"`
