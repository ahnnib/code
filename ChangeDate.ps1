# Function to change creation and modification dates of a file or folder
param (
    [string]$itemPath, 
    [datetime]$newDate
)

# Get the item (file or folder)
$item = Get-Item $itemPath

# Update the creation time
$item.CreationTime = $newDate

# Update the modification time
$item.LastWriteTime = $newDate

# Update the access time (optional, can be removed if not needed)
$item.LastAccessTime = $newDate

Write-Host "Dates updated for: $itemPath"