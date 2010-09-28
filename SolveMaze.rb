class SolveMaze
  NORTH = 0
  SOUTH = 2
  EAST = 1
  WEST = 3

  def self.right_hand(maze)
    direction = SOUTH
    cur_loc = [0, 0]
    while (cur_loc != [maze.size-1, maze[1].size-1])
      print_maze(maze, cur_loc)
      next_direction = (direction + 1) % 4
      while true
        # p next_direction
        next_loc = location_to_direction(maze, cur_loc, next_direction)
        # p next_loc
        break if (next_loc && maze[next_loc[0]][next_loc[1]])
        next_direction = (next_direction - 1) % 4
      end
      cur_loc = location_to_direction(maze, cur_loc, next_direction)
      direction = next_direction
    end
  end

  def self.location_to_direction(maze, loc, dir)
    new_loc = nil
    case dir
    when NORTH
      new_loc = [loc[0]-1, loc[1]]
    when EAST
      new_loc = [loc[0], loc[1]+1]
    when SOUTH
      new_loc = [loc[0]+1, loc[1]]
    when WEST
      new_loc = [loc[0], loc[1]-1]
    else
      return nil
    end
    # p "#{new_loc.inspect}: #{maze.size} - #{maze[0].size}"

    if (new_loc[0] >= 0 && new_loc[0] < maze.size && new_loc[1] >= 0 && new_loc[1] < maze[0].size)
      return new_loc 
    else
      return nil
    end
  end

  def self.print_maze(maze, cur_loc)
    puts "===================="
    for row in (0..maze.size-1)
      for column in (0..maze[1].size-1)
        if row == cur_loc[0] && column == cur_loc[1]
          print "#"
        else
          print maze[row][column] ? "0" : "1"
        end
      end
      puts "\n"
    end
  end
end
