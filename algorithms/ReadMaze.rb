class ReadMaze
  def self.fetch(filename)
    
    file = File.new(filename, "r")
    line = file.gets
    size = line.split(" ")
    maze = Array.new(size[0].to_i).map!{Array.new(size[1].to_i)}
    row = 0
    while (line = file.gets)
      if (row < size[0].to_i)
        column = 0
        line.split(" ")[0].split("").each do |char|
          maze[row][column] = (char == "0")
          column += 1
        end
        row += 1
      end
    end

    maze
  end
end
