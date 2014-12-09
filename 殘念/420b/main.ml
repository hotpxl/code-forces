open Set

exception InvalidInput

module IntSet = Set.Make(
  struct
    let compare = Pervasives.compare
    type t = int
  end
)

type status =
  | Uninitialized
  | FoundOnline of int
  | FoundOffline of int
  | NotFound

let (|>) x f = f x

let rec makeList = fun len f ->
  if len = 0 then
    []
  else
    (f ()) :: (makeList (len - 1) f)

let rec range = fun s e ->
  if s < e then
    s :: range (s + 1) e
  else
    []

let findHidden = fun records n ->



let () =
  let (n, m) = read_line ()
  |> Str.split (Str.regexp " +")
  |> List.map int_of_string
  |> fun li ->
    match li with
    | a :: [b] ->
      (a, b)
    | _ ->
      raise InvalidInput
  in
  let records = makeList m (fun () ->
    read_line ()
    |> Str.split (Str.regexp " +")
    |> fun li -> match li with
      | a :: [b] ->
        ((if a = "+" then 1 else 0), (int_of_string b))
      | _ ->
        raise InvalidInput
  )
  in
  ignore (find_never_appeared records);
  ()
